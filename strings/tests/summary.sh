#!/bin/bash

passed=0
failed=0

echo
echo "=================SUMMARY================="

for test in ./test_*; do
    if [ -x "$test" ]; then
        name=${test#./test_}
        if "$test" > /dev/null 2>&1; then
            printf "test_%-30s \033[32mPASS\033[0m\n" "$name"
            ((passed++))
        else
            printf "test_%-30s \033[31mFAIL\033[0m\n" "$name"
            ((failed++))
        fi
    fi
done

echo "-----------------------------------------"
echo "Passed: $passed | Failed: $failed"
echo "========================================="