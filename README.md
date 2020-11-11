# Table of contents

* [About](#About)
* [Building](#Building)
* [Mirror List](#Mirror-List)
* [License](#License)
* [Contact Info](#Contact-Info) <br><br><br><br>





### About<br>

**Survivio** is a desktop clone of the popular browser battle royale shooter - [surviv.io](https://surviv.io/), written in C++.
The project is currently in the stage of an early alpha development, so any contribution via pull request or issue is welcome.
At the moment, only Linux and Windows platforms are fully supported, MacOS support will arrive soon. <br><br><br><br>





### Building

1. Satisfy the SFML dependencies, if needed (https://www.sfml-dev.org/faq.php)


2. Install the latest version of [Cmake](https://cmake.org/download/)
   and any corresponding build tool + compiler (see list of supported below)


3. In the terminal write (to clone the repository on your computer): <br>
```
        git clone https://github.com/Fenex330/Survivio.git
```

4. Make a directory called "build" within the Survivio directory (either through the terminal or your file explorer): <br>
```
        mkdir Survivio/build/
```

5. Then write (or use cmake gui to configure and generate native build files): <br>
```
        cd Survivio/build/
        cmake .. && cmake --build .
```

The folder "Survivio/build/bin" will contain all the binary files.

Note that on windows, you must manualy move the dll files from "lib" folder to the binary root folder (bin) next to the executable <br><br>



Tested to be working on:

* Compilers - *g++, clang++* <br>
* build tools - *make, ninja, CodeBlocks project files, CodeLite project files* <br><br><br><br>





### Mirror List

Primary https://github.com/Fenex330/Survivio

Secondary https://notabug.org/Fenex33/Survivio <br><br><br><br>





### License

Distributed under [MIT License](./LICENSE.txt) <br><br><br><br>





### Contact Info

For any questions or queries contact anonimus33@protonmail.com
