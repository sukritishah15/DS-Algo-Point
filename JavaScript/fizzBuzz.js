const fizzBuzz = (startPoint, endPoint) => {
  for (let i = startPoint;  i < endPoint; i+=1) {
    if(i % 15 === 0) {
      console.log('FizzBuzz')
    } else if (i % 3 === 0) {
      console.log('Fizz')
    } else if (i % 5 === 0) {
      console.log('Buzz')
    } else console.log(i)
  }
};
const startPoint = 1;
const endPoint = 100;
fizzBuzz(startPoint, endPoint);
