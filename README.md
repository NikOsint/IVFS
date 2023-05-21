# IVFS

Virtual File System written in C++ for Linux.

It uses a ZIP archive to store files, so you can read and write multiple files while only one is opened.

## How it works

[Poco::Zip](https://docs.pocoproject.org/current/Poco.Zip.html) is used for ZIP manipulations.

```std::mutex``` is used for allowing multithreaded access.

## How to build

Firstly, ensure that you do have the Poco package installed.

If not, install it according to the [guide](https://pocoproject.org/download.html).

A simple way to do that is to use the apt package manager:

```shell
sudo apt install libpoco-dev
```

To build the console app for testing the IVFS functuanality, execute the following commands:

```shell
mkdir build && cd build
cmake ..
make
```

Now in the ```build``` directory you can find the ```ivfs.exe``` executable.

## How to run

After building the console app, just execute the ```ivfs.exe```.

If you are in the IVFS root directory, type:

```shell
./build/ivfs.exe [archive name]
```

The list of available commands is as follows:

| Command                       | Description                        |
|-------------------------------|------------------------------------|
| ```open [filename]```         | Open file in readonly mode         |
| ```create [filename]```       | Create/Open file in writeonly mode |
| ```read [filename]```         | Read from a previously opened file |
| ```write [filename] [data]``` | Write to a previously opened file  |
| ```close [filename]```        | Close a previously opened file     |     
| ```q```                       | Quit                               |

> Typing data through console to write to a file is not very practical, so unit tests with real data are needed.
> 
> TIP: cover data in double quotes so that spaces do not act as delimeters.

## TODOs

- [ ] Implement unit tests
- [ ] Implement connecting more than one ZIP archive
- [ ] Implement in-memory filesystem to store temporary files
- [ ] Rewrite to use another library so that there is no need to save and delete temporary files in native filesystem