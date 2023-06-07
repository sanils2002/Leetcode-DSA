/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currentValue = init;

  function increment() {
    currentValue++;
    return currentValue;
  }

  function decrement() {
    currentValue--;
    return currentValue;
  }

  function reset() {
    currentValue = init;
    return currentValue;
  }

  return {
    increment,
    decrement,
    reset
  };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */