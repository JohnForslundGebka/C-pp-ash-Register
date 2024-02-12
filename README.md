# C-pp-ash-Register

 Description

It's a little hobby project for me. I'm trying to model something that could be in a store. 


# Features
Article Management: Add, update, and remove articles from the inventory.
Categorization: Organize articles into categories such as books, clothing, and laptops.
Stock Tracking: Monitor the quantity available for each article.
Sales Functionality: Process sales transactions and adjust stock levels accordingly.

# Prerequisites
C++17 compatible compiler (GCC, Clang, MSVC)
SQLiteCpp library (or equivalent SQLite wrapper for C++)
CMake 

# Installation
1. Clone the repository including submodules:
This project uses SQLiteCpp as a git submodule. To clone the repository and the submodule at the same time, use the --recurse-submodules option with git clone:

```git clone --recurse-submodules https://github.com/JohnForslundGebka/C-pp-ash-Register```

If you have already cloned the project just write

```git submodule update --init --recursive```

2. Use CMake to build

# Usage
After launching the console application, follow the on-screen prompts to interact with the inventory system. Operations include adding new articles, viewing existing inventory, processing sales, and updating stock levels.

