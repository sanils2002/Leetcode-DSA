/**
 * @param {Object} obj
 * @return {Object}
 */
var compactObject = function(obj) {
    if(Array.isArray(obj)) {
        // If obj is an array, filter out the falsy values
        return obj.filter(Boolean).map(compactObject);
    } 
    else if(typeof obj === 'object' && obj !== null) {
        // If obj is an object, iterate over its keys and compact each value
        return Object.entries(obj).reduce((acc, [key, value]) => {
            const compactValue = compactObject(value);
            if(Boolean(compactValue)) {
                acc[key] = compactValue;
            }
            return acc;
        }, {});
    }
  
    // Return obj if it is not an object or array, or if it is a truthy value
    return obj;
};