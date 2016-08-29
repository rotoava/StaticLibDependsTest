工程：Test_a_0 包含两个类 a0file 和 a1file. 最后编译结果成静态库 libTest_a_0.a 

```

➜  Debug-iphoneos git:(master) ✗ otool -hv libTest_a_0.a
Archive : libTest_a_0.a
libTest_a_0.a(a0file.o):
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64   ARM64        ALL  0x00      OBJECT     8       2264 SUBSECTIONS_VIA_SYMBOLS
libTest_a_0.a(a1file.o):
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64   ARM64        ALL  0x00      OBJECT     8       2264 SUBSECTIONS_VIA_SYMBOLS

// 包含两个.o文件

```

工程：Test_a_2 包含一个类 Test_a_2，  并且依赖  libTest_a_0.a。 最后编译结果成静态库 libTest_a_2.a 

```
➜  Debug-iphoneos git:(master) ✗ otool -hv  libTest_a_2.a
Archive : libTest_a_2.a
libTest_a_2.a(Test_a_2.o):
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64   ARM64        ALL  0x00      OBJECT     8       2424 SUBSECTIONS_VIA_SYMBOLS
libTest_a_2.a(a0file.o):
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64   ARM64        ALL  0x00      OBJECT     8       2264 SUBSECTIONS_VIA_SYMBOLS
libTest_a_2.a(a1file.o):
Mach header
      magic cputype cpusubtype  caps    filetype ncmds sizeofcmds      flags
MH_MAGIC_64   ARM64        ALL  0x00      OBJECT     8       2264 SUBSECTIONS_VIA_SYMBOLS

// 包含三个.o文件

```

工程：Test_a_3 与 Test_a_2类似。依赖共同的  libTest_a_0.a

工程：Test_a_dubpl 最终测试工程。依赖  Test_a_3 和  Test_a_2。


结论：
1.两个静态库a&b 共同依赖第三个静态库c。 a b 可以用在同一工程之中。
2.如果共同依赖的 c 有差异。不能确定最终是编译链接的哪个c。
3.最后工程还可以使用 c 的api ，只需要把头文件加入工程即可。
4.c中未被 ab使用到的.o文件也会直接被囊括到ab的编译结果之中。？


