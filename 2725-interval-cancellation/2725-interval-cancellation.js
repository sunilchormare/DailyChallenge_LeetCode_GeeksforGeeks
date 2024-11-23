function cancellable(fn: Function, args: any[], t: number): Function {
  let timerId = null;
  fn(...args);

  const startInterval = (): void => {
    timerId = setTimeout(() => {
      fn(...args);
      startInterval();
    }, t);
  };
  startInterval();

  const cancelInterval: Function = (): void => {
    if (timerId !== null) {
      clearTimeout(timerId);
    }
  };

  return cancelInterval;
}