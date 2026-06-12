# EmbedKit_Naveena

## Developer Information
**Name:** Naveena Batchanaboina

## Project Overview
This project implements a fixed-size Ring Buffer (Circular Buffer) in C for uint8_t data.

A Ring Buffer is a FIFO (First-In-First-Out) data structure commonly used in embedded systems for communication between interrupt service routines (ISRs) and application tasks. It efficiently handles continuous data streams while reusing memory through circular indexing.

This implementation supports:

- Buffer Initialization
- Write Operation
- Read Operation
- Buffer Full Detection
- Buffer Empty Detection
- Data Count Retrieval
- Circular Wrap-Around Handling
- Overflow and Underflow Protection

---

## Module Description

### ringbuf.c
Implements an 8-byte circular buffer using uint8_t data type.

Features:
- Fixed buffer size of 8 bytes
- FIFO operation
- Prevents overwrite when buffer is full
- Prevents invalid reads when buffer is empty
- Supports wrap-around indexing
- Demonstrates all required test cases in main()

---

## Directory Structure
EmbedKit_Naveena/
│
├── ringbuf.c
├── README.md


---

## Build Instructions

Compile using GCC:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf

Run:

./ringbuf
