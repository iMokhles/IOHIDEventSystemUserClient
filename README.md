# IOHIDEventSystemUserClient
iOS Kernel Race Vulnerability (Patched 9.3.2 by Apple)

#How to...
1-)Open Terminal

2-) Enter the this command:

```git clone https://github.com/yigitcanyilmaz/IOHIDEventSystemUserClient.git && cd IOHIDEventSystemUserClient && gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch <target> -isysroot <SDK> -I<FilePath>```
# For Example
```git clone https://github.com/yigitcanyilmaz/IOHIDEventSystemUserClient.git && cd IOHIDEventSystemUserClient && gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch armv7s -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS9.3.sdk -I/Users/yigityilmaz/Desktop/IOHIDEventSystemUserClient```

#OR ...
1-) Download zip file

2-) Enter the Folder with ```cd``` command.

3-) Enter the This Command :

gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch <target> -isysroot <SDK> -I<FilePath>

#For Example (zip file)

gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch armv7s -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS9.3.sdk -I/Users/yigityilmaz/Desktop/IOHIDEventSystemUserClient
