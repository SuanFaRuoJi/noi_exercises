#!/bin/bash

upper=$(echo $1 | tr 'a-z' 'A-Z')

cat << END
#ifndef ${upper}_SOLUTION
#define ${upper}_SOLUTION
#endif
END
