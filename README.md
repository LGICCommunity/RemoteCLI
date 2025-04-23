# RemoteCLI 

## Overview
RemoteCLI is a lightweight client-server tool designed to allow remote execution of shell commands over a TCP connection. It is written in C and provides a basic mechanism for connecting a remote terminal to a host system.

---

## Architecture
RemoteCLI is composed of two main components:

### 1. Server (`server.c`)
- Listens for TCP connections on a configurable port (default: `8080`)
- Accepts a single client connection at a time
- Receives command strings from the client
- Executes the command using `popen()` and captures the output
- Sends the command output back to the client line-by-line
- Sends `__END__` as a delimiter to indicate the end of command output

### 2. Client
- Connects to the server using IPv4 TCP
- Sends shell commands to the server
- Receives and prints the output from the server
- Sends `exit` to terminate the session

---

## Protocol Details
- Communication is plain TCP
- Data is exchanged as raw strings
- A special delimiter string `__END__` is used to indicate the end of a command's output

---

## Limitations
- Single client support only
- No authentication or encryption (not suitable for production use without additional security layers)
- Minimal error handling
- Shell command execution is not sandboxed — **potentially unsafe**

---
