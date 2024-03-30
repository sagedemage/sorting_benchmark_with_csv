#!/bin/sh

cd java
javac Main.java
echo "Java"
java Main
echo ""

cd ../csharp
dotnet build --configuration Release -v q
echo "C#"
dotnet bin/Release/net8.0/csharp.dll
echo ""

cd ../javascript
echo "JavaScript"
npm start
echo ""

cd ../cpp
echo "C++"
make
make run
echo ""

cd ../rust
echo "Rust"
cargo build --release -q
./target/release/rust
echo ""

cd ../c
echo "C"
make
make run
echo ""

cd ../go
echo "Go"
go build -ldflags "-s -w" -o out
./out
echo ""

cd ../python 
echo "Python"
python3 main.py

