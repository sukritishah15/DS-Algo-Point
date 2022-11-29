"use strict";

// Number of characters in our alphabet (Note: if we only use numbers d = 10)
const d = 256;

const hashForH = (M, q) => {
  let h = 1;
  for (let i = 0; i < M - 1; i++) {
    h = (h * d) % q;
  }
  return h;
};

const hashAndWindow = (text, pattern, M, q) => {
  let p = 0;
  let t = 0;
  for (let i = 0; i < M; i++) {
    p = (d * p + pattern[i].charCodeAt(0)) % q;
    t = (d * t + text[i].charCodeAt(0)) % q;
  }
  return { p, t };
};

const rabinKarp = (text, pattern, q) => {
  const M = pattern.length;
  const N = text.length;

  const h = hashForH(M, q);

  const results = hashAndWindow(text, pattern, M, q);

  let p = results.p;
  let t = results.t;

  let i = 0, j = 0;

  for (i = 0; i <= N - M; i++) {
    if (p === t) {
      for (j = 0; j < M; j++) {
        if (text[i + j].charCodeAt(0) !== pattern[j].charCodeAt(0)) break;
      }

      if (j === M) console.log(`Pattern found at index ${i}`);
    }

    if (i < N - M) {
      t = (d * (t - text[i].charCodeAt(0) * h) + text[i + M].charCodeAt(0)) % q;

      if (t < 0) t = t + q;
    }
  }
};

const test = () => {
  const text = [..."ABBABABBBABAAB"];
  const pattern = [..."ABB"];

  // Prime number
  const q = 17;
  
  rabinKarp(text, pattern, q);
};

test();

/*
  Input : 
          text (Array<string>): [..."ABBABABBBABAAB"]
          pattern (Array<string>): [..."ABBABABBBABAAB"]
  OutPut: 
          Pattern found at index 0
          Pattern found at index 5
  Time:  
        Best case: O(N + M)
        Worst case: O((n-m+1) m) | O(N * M)
  Space: O(N + M)
*/