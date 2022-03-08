find . -name problem.cpp | sort | awk -F'/' '{print $3" "$0}' | sort -n | awk -F' ' '{print $2}'
