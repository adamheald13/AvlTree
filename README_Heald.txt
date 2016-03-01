EECS 560 Data Structures Lab04 - Adam Heald

Testing: To run the program, use the make command and then run the Lab04 executable.
  My testing for this program consisted of testing very small AVL trees of size 3 and using those to test my rotations and insertions on.
  Once those tests were complete I would enter the full data set. Each time this worked.
  Then I tested my deletions in the same manner. I would delete the target node, and then review the resultng AVL tree to verify its correctness.

Notes:
  The program only supports cities of single words. This is why some of my cities do have a space where they should. e.g. Kansas City is really KansasCity in the db.

Lab05 Discussion:
  According to my test data, insertions are always faster on the unordered array
  as there are never any comparisons that need to be made. But, when it comes to
  deletion, AVL trees are much more efficient. In my test, the unordered array
  required 10x as many comparisons to delete the same data. I believe that for
  the distance function the unordered array would be the 'best'. Since the
  distance functions require visiting every single element in the data structures,
  it is much simpler to visit each element in the array rather than do a full
  traversal of the AVL tree.
