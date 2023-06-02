/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let updatedArr = [];
    for(let i=0; i<arr.length; i++) {
        if(fn(arr[i], i)) {
            updatedArr.push(arr[i])
        }
    }
    return updatedArr
};