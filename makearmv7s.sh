# Created by YigitCan
# for ARMV7S

gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch armv7s -isysroot "$(xcrun --show-sdk-path --sdk iphoneos)" -framework IOKit -I"$(pwd)"
ldid -Sdbg.xml IOHIDEventSystemUserClient