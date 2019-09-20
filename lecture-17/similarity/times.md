```
g++ -std=c++11 -O3 -Wall -Wextra -Wconversion similarity.cpp -o similarity
python similarity.py u.data sim_cpy.txt
Input MovieLens file: u.data 
Output file for similarity data: sim_cpy.txt
Minimum number of common users: 5

Read 100000 lines with total of 1682 movies and 943 users

Computed similarities in 39.075 seconds
pypy similarity.py u.data sim_pypy.txt
Input MovieLens file: u.data 
Output file for similarity data: sim_pypy.txt
Minimum number of common users: 5

Read 100000 lines with total of 1682 movies and 943 users

Computed similarities in 19.097 seconds
./similarity u.data sim_cpp.txt
Input MovieLens file: u.data
Output file for similarity data: sim_cpp.txt
Minimum number of common users: 5
Read 100000 lines with total of 1682 movies and 943 users
Computed similarities in 4.83 seconds
```
