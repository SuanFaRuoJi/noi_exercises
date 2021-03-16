#!/bin/bash

import_list='iostream cstdlib'

for i in $import_list; do
	printf "#include <$i>\n"
done

printf "\n#include \"$1.h\"\n\n"

printf "using namespace std;\n\n"

cat << END
int main() {
  cout << "This problem <$1> hasn't been implemented yet" << endl;
  return -1;
}
END


