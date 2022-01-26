<h1 align="center">
	pipex
</h1>

<p align="center">
	This project was made in accordance with the project of School 21 (Ecole 42).
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/haimasker/pipex?color=blue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/haimasker/pipex?color=blue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/haimasker/pipex?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/haimasker/pipex?color=blue" />
</p>

<h3 align="center">
	<a href="#preamble">Preamble</a>
	<span> · </span>
  <a href="#description">Description</a>
	<span> · </span>
	<a href="#installation">Installation and usage</a>
</h3>

---

<a name="preamble"></a>
## Preamble

The purpose of this project is to simulate UNIX mechanism - pipe.

You can see the subject here: [pipex](en.subject.pdf).

Main requirements, rules and code style: [Norm](en_norm.pdf).

---

<a name="description"></a>
## Description

### Mandatory part

* Our objective is to code ``pipex`` that should be executed in this way:

```shell
./pipex file1 cmd1 cmd2 file2
```
* Execution of ``pipex`` should be similar to the next shell command:

```shell
< file1 cmd1 | cmd2 > file2
```

``file1``, ``file2`` - filenames

``cmd1``, ``cmd2`` - shell commands with their parameters

<br>

* Handling errors must be like in shell

### Bonus part

* ``pipex`` should handle multiple pipes:

```shell
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

is equivalent to next shell command:

```shell
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

<br>

* ``pipex`` should support `«` and `»` when the first parameter is `here_doc`:

```shell
./pipex here_doc LIMITER cmd1 cmd2 file
```
is equivalent to next shell command:

```shell
cmd1 << LIMITER | cmd2 >> file
```

---

<a name="installation"></a>
## Installation and usage

* Clone this repository:

```shell
git clone https://github.com/Haimasker/pipex.git
```

* Go to the project folder:

```shell
cd pipex
```

* To compile mandatory part:

```shell
make
```

* To compile bonus part:

```shell
make bonus
```

* After compilation just run ``pipex`` with your parameters.
