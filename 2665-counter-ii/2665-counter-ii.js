/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = (init) => {
    let counter = init;
    const increment = () => ++counter;
    
    const decrement = () => --counter;
    
    const reset = () => {
        counter = init;
        return counter;
    }
    
    return {increment, decrement, reset}
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */