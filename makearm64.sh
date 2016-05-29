# Created by YigitCan
# for ARM64

gcc IOHIDEventSystemUserClient.c -o IOHIDEventSystemUserClient -arch arm64 -isysroot "$(xcrun --show-sdk-path --sdk iphoneos)" -framework IOKit -I"$(pwd)"