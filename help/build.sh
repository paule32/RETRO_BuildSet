#!/bin/bash

qhelpgenerator help.qhp -o help.qch
assistant -register help.qch

#echo "generators..."
qcollectiongenerator help.qhcp -o help.qhc
assistant -collectionFile help.qhc