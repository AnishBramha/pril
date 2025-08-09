# The `PRiL` Text Editor

`PRiL` is a free and open source text editor developed using the `wxWidgets` GUI library in `C++`. It supports all major text formats and runs on all major platforms (Linux, macOS and Windows).

## Contribution
Pull requests are welcome! Please contribute to improve this project and provide suggestions by raising issues.

## Table of Contents
* [Installation](#installation)
* [Build from source](#build-from-source)
    - [Dependencies](#install-dependencies)
        - [Package Manager](#1-package-manager)
        - [Development Tools](#2-cc-compiler-and-tools)
        - [GNU `Make`](#3-make)
        - [GUI Library](#4-wxwidgets)
    - [Build and run](#build-and-run-project)
        - [Recommended execution](#1-clean-run)
        - [Generate intermediates](#2-generate-compilation-and-linking-intermediates)
        - [Run without using `make`](#3-run-without-using-make)

## Installation

To install the executable wrappers directly, check out the [latest release](https://github.com/AnishBramha/pril/releases/tag/v1.0.0). Download and extract to get the executable.

> [!TIP]
> You might need to disable gatekeeping mechanisms temporarily as this release lacks a signed certificate.

## Build from source

Get the source code from the [release](https://github.com/AnishBramha/pril/releases/tag/v1.0.0) page.

### Install dependencies
---

#### 1. Package Manager
* Get [`chocolatey`](https://chocolatey.org/) for **Windows**.

* Get [`homebrew`](https://brew.sh/) for **macOS** by running the following command on `bash`/`zsh`:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

> [!IMPORTANT]
> Add to path by running the following two commands:
```
(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> ~/.zprofile

eval "$(/opt/homebrew/bin/brew shellenv)"
```

* This build guide covers `apt`, `dnf` and `pacman`, which are usually the default package managers on Debian-based, RedHat-based and Arch-based **Linux** distros.

#### 2. `C`/`C++` compiler and tools

* On **Windows**, install [`minGW64`](https://www.mingw-w64.org/) by running the following command in PowerShell with administrator privileges:
```
choco install mingw
```
> [!IMPORTANT]
> Verify if `minGW` is added to path by running `$env:Path` in PowerShell and check if the path to the `bin` folder is visible. If not, edit the System Environment Variables and add it to path manually.

* On **macOS**, install the `Xcode` command line tools by running:
```
sudo xcode-select --install
```

* On **Linux**, run the following commands, based on your package manager:
```
sudo apt-get install build-essential

sudo dnf group install "C Development Tools and Libraries" "Development Tools"

sudo pacman -S base-devel
```

> [!TIP]
> To verify installation, run:
```
g++ --version
```

#### 3. `Make`

This project uses [`GNU make`](https://www.gnu.org/software/make/) to run makefiles for easier compilation, linking and execution.

> [!NOTE]
> If you do not want to use `make`, skip to [GUI library](#4-wxwidgets)

* On **Windows**, run in PowerShell admin:
```
choco install make
```

> [!TIP]
> To verify installation, run:
```
make --version
```

* On **macOS**, `make` is installed with the `Xcode` command line tools.

* On **Linux**, `make` comes packaged with `build-essential`/`base-devel`.

#### 4. `wxWidgets`

[`wxWidgets`](https://wxwidgets.org/) is a cross-platform free and open source GUI library with support for building native-looking OS-agnostic applications.

* On **Windows**, run in PowerShell admin:
```
choco install wxwidgets
```

* On **macOS**, run in `bash`/`zsh`:
```
brew install wxwidgets
```

* On **Linux**, follow the steps provided in the documentation in the [official documentation](https://wiki.wxwidgets.org/Compiling_and_getting_started)

> [!TIP]
> To verify installation, run:
```
wxwidgets --version
```

> [!NOTE]
> If you skipped installing `make`, jump directly to [raw run](#3-run-without-using-make).


### Build and run project
---

#### 1. Clean run

> [!NOTE]
> Recommended for a cleaner compilation and execution.

* To generate the executable (_only_) and start the application automatically, run the following command in the **project directory**:
```
make run
```

#### 2. Generate compilation and linking intermediates


* To generate the intermediate object files along with the executable, run the following command in the **project directory**:
```
make all
```

* On **Windows**, run:
```
./pril-editor.exe
```

* On **macOS** and **Linux**, run:
```
./pril-editor
```

To clean up the project directory and remove the object files, run:
```
make clean
```


#### 3. Run without using `make`

To generate the object files, run the following command in the **project directory**:
```
g++ -std=c++17 -c `wx-config --cxxflags` App.cpp Frame.cpp
```

* To generate the executable on **Windows**, run:
```
g++ -o pril-editor.exe `wx-config --libs` App.o Frame.o
```

* On **macOS** and **Linux**, run:
```
g++ -o pril-editor `wx-config --libs` App.o Frame.o
```

Alternatively, to generate the executable directly, run:
* On **Windows**:
```
g++ -std=c++17 -o pril-editor.exe `wx-config --cxxflags --libs` App.cpp Frame.cpp
```

* On **macOS** and **Linux**:
```
g++ -std=c++17 -o pril-editor.exe `wx-config --cxxflags --libs` App.cpp Frame.cpp
```

Run the executable as given in [previous section](#2-generate-compilation-and-linking-intermediates).
