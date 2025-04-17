# RemoteCLI
## Project: Remote Terminal Access Using C (CLI Based)

---

### 1. Objective

Develop a C-based application to remotely access and execute terminal commands on another machine via TCP sockets, allowing basic communication between client and server through CLI.

---

### 2. Key Features

- Client sends terminal commands.
    
- Server executes the command.
    
- Server returns a success message (or output).
    
- Pure C implementation using Linux socket programming.
    

---

### 3. Use Case Scenario

You (client) want to execute commands on your friend's (server) machine sitting in another room. You connect to their IP, send commands, and get confirmation back.

---

### 4. Tools and Technologies

- Language: C
    
- Platform: Linux (Ubuntu recommended)
    
- Compiler: GCC
    
- Concepts: TCP/IP Sockets, CLI I/O, Basic Networking
    

---

### 5. System Requirements

- Two machines in the same LAN (or use port forwarding for WAN).
    
- Terminal access (Linux bash).
    
- Open ports and no firewall blockage on server side.
    

---

### 6. Architecture Diagram

```
+-------------------+                       +---------------------+
|                   |  TCP Connection (8080)|                     |
|     CLIENT        | <-------------------> |      SERVER         |
|                   |                       |                     |
|  - Send command   |                       | - Receive command   |
|  - View response  |                       | - Execute using C   |
|  - CLI Interface  |                       | - Respond result    |
+-------------------+                       +---------------------+
```

---

### 7. System Flow Diagram

```
[Client]              [Network]            [Server]
   |                       |                   |
   |--- Connect to Server --->                |
   |                       |<--- Accept -------|
   |--- Send Command ------>                  |
   |                       |--- Execute ------> (system())
   |                       |<-- Output/Msg ----|
   |<-- Display Output ----                   |
```

---

### 8. Implementation Steps

#### Step 1: Server Side Code

- Create a socket
    
- Bind to port (e.g., 8080)
    
- Listen for incoming connection
    
- Accept client connection
    
- Continuously read incoming commands
    
- Execute commands using `system()` or `popen()`
    
- Send response back to client
    

#### Step 2: Client Side Code

- Create socket
    
- Connect to server IP:PORT
    
- Input commands from user (using `fgets`)
    
- Send commands over socket
    
- Receive response from server
    
- Print output on CLI
    

---

### 9. Sample Command Flow

```bash
Client> ls
Server> Executes "ls"
Server> Returns: file1.txt file2.c main.o
Client> Displays output
```

---

### 10. Security Concerns

- No encryption (plain text commands).
    
- Arbitrary command execution (risky without filters).
    
- Use only in a secure LAN environment or with known devices.
    
- For real-world use, add authentication and SSL.
    

---

### 11. Future Enhancements

- Command output transfer (full response, not just "Executed").
    
- Add authentication (username & password).
    
- Encrypt communication using OpenSSL.
    
- File transfer support.
    
- Cross-platform support.
    

---

### 12. Real-World Use Inspiration

- SSH-like remote control
    
- Remote administration
    
- Classroom computer monitoring
    
- IoT device command control
    

---

### 13. Project Folder Structure

```
/remote-terminal/
  ├── client.c
  ├── server.c
  ├── README.md
  └── Makefile (optional)
```

---

### 14. Presentation Tip

Show a live demo using 2 virtual machines or real systems in LAN:

- Run ./server on one.
    
- Run ./client on another, connect, and type:
    
    ```
    ls
    date
    ```This is your new *vault*.

Make a note of something, [[create a link]], or try [the Importer](https://help.obsidian.md/Plugins/Importer)!

When you're ready, delete this note and make the vault your own.
