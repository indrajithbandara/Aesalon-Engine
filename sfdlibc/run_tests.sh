clang test/sfd_ctype_test.c -o sfd_ctype_test
./sfd_ctype_test > test_results.txt
grep "Fail" test_results.txt
rm sfd_ctype_test test_results.txt
