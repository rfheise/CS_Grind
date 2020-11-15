echo "Testing Python Speed"
cd python
time python3 Hash.py

echo "Running Java"
cd ..
cd Java
time java Hash
echo "Running crappy shared pointers C++"
cd ..
cd Smarts
time ./bat

echo "Running Speedy Boi C++"
cd ..
cd noSmarts
time ./bat

cd ..
