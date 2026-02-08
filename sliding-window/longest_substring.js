function getLongestSubstring(str) {
    const n = str.length;
    const last = new Array(256).fill(-1);
    let l = 0, maxLen = 0;
    for (let r = 0; r < n; r++) {
        const code = str.charCodeAt(r);
        if (last[code] >= l) l = last[code] + 1;
        maxLen = Math.max(maxLen, r - l + 1);
        last[code] = r;
    }
    return maxLen;
}

console.log(getLongestSubstring("abbbacabdca"));
