function numberOfSubstrings(str) {
  let n = str.length;
  let left_ptr = 0;
  let right_ptr = 0;
  let cnt = 0;
  const mpp = new Map();

  while (right_ptr < n) {
    mpp.set(str[right_ptr], (mpp.get(str[right_ptr]) || 0) + 1);

    while (mpp.size === 3) {
      cnt += n - right_ptr;

      mpp.set(str[left_ptr], mpp.get(str[left_ptr]) - 1);
      if (mpp.get(str[left_ptr]) === 0) {
        mpp.delete(str[left_ptr]);
      }
      left_ptr++;
    }
    right_ptr++;
  }
  return cnt;
}

const cnt = numberOfSubstrings("abcabc");
console.log(cnt);
