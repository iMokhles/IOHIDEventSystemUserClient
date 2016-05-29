# Created by YigitCan
# for ARMV7

gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch armv7 -isysroot "$(xcrun --show-sdk-path --sdk iphoneos)" -framework IOKit -I"$(pwd)"
ldid -Sdbg.xml IOHIDEventSystemUserClient