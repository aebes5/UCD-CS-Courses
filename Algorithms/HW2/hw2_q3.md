## Loop Invariant:

The loop invariant is something that holds true for each step in the loop; that is, the loop invariant holds true for the initialization step, maintenance step, and termination step - based on the end goal or desired outcome.

---

## Loop Invariant in Merge Sort:

In the merge sort the loop invariant could be described as correctly sorting each sublist that is generated each time the list splits - such that when the sublists are merged at each level, the original list is sorted.

---

## Initialization Step:

The initialization step could be classified as making sure the list is properly formatted and needs split; that is, when the algorithm takes in the list it can properly split the original list into two sublists.

---

## Maintenance Step:

For some arbitrary iteration in the loop, the conditions hold where the sublist provided can split into two more sublists.

---

## Termination Step:

Once the sublists can no longer be split into two, each sublist is sorted and then merged up one level where the process repeats until the original, sorted, list is returned. 