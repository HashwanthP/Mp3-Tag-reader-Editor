# 🎵 MP3 Tag Reader & Editor in C

A command-line MP3 Tag Reader & Editor developed in C that allows users to view and modify ID3 metadata tags in MP3 files.This project focuses on binary file handling, command-line processing, and understanding real-world file formats at the byte level.

🚀 Project Overview

MP3 files store metadata using **ID3 tags**.This project reads and edits **ID3v2 metadata frames** directly from the binary structure of the file.

🔍 Tags Supported

🎵 Title (TIT2) 
🎤 Artist (TPE1) 
💿 Album (TALB) 
📅 Year (TYER) 
🎼 Genre (TCON) 
📝 Comment (COMM)
The program validates the MP3 file using the ID3 header before processing.

✅ Key Features

- View MP3 metadata tags  
- Edit specific metadata fields  
- Command-line argument based execution  
- MP3 file validation using ID3 header  
- Safe editing using temporary file handling  
- Modular and structured C program design  

🛠 Technical Concepts Used

- File handling (binary files)  
- Command-line arguments (argv)  
- Pointer manipulation  
- Dynamic memory allocation  
- String handling  
- Bitwise operations  
- Endianness conversion (Little ↔ Big Endian)  
- Byte-level data parsing  

⚙️ How It Works

- Reads ID3 header to validate MP3 file  
- Parses metadata frames (e.g., TIT2, TPE1)  
- Converts size values using endianness conversion  
- Copies data to a temporary file while modifying selected tag  
- Replaces original file after editing  

#View Tags

./mp3_tag -v song.mp3

#Edit Tags

./mp3_tag -e -t "New Title" song.mp3

🎯 Learning Outcome
- Understanding ID3 metadata structure
- Working with binary file data in C
- Building command-line utilities
- Handling real-world file formats
- Writing modular and maintainable code

🔧 Future Improvements
- Support more ID3 frames
- Improve error handling
- Batch processing for multiple files
- User-friendly interface
