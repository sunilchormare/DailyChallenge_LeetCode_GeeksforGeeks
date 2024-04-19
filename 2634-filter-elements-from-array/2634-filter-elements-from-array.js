/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let currentIndex = 0;

 for (let i = 0; i < arr.length; i++) {
   if (fn(arr[i], i)) {
     arr[currentIndex] = arr[i];
     currentIndex++;
   }
 }

 arr.length = currentIndex;
 return arr;
};