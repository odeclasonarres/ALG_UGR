#!/bin/bash

touch sumalineal.dat

i=1000
while [  $i -lt 100000 ]; do
    ./suma $i >> sumalineal.dat
    let i=i+1000
done
