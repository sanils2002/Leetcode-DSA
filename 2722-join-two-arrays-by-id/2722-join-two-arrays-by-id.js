/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let mergedObjects = {};

    // Merge objects from arr1
    for(let obj of arr1) {
        const { id, ...rest } = obj;
        if(!mergedObjects.hasOwnProperty(id)) {
            mergedObjects[id] = { ...rest };
        } 
        else {
            mergedObjects[id] = { ...mergedObjects[id], ...rest };
        }
    }

    // Merge objects from arr2
    for(let obj of arr2) {
        const { id, ...rest } = obj;
        if(!mergedObjects.hasOwnProperty(id)) {
            mergedObjects[id] = { ...rest };
        } 
        else {
            mergedObjects[id] = { ...mergedObjects[id], ...rest };
        }
    }

    let joinedArray = [];

    // Build the final array
    for(let id of Object.keys(mergedObjects).sort((a, b) => a - b)) {
        joinedArray.push({ id: parseInt(id), ...mergedObjects[id] });
    }

    return joinedArray;
};