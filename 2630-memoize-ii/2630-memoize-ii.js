function memoize(fn) {
   const map = {};
   const idPool = new Map();
   function getId(item) {
       return idPool.get(item)?? idPool.set(item, idPool.size + 1).get(item);
   }
   return function(...args) {
       const key = args.map(getId).join("-");
       return map[key]?? (map[key] = fn(...args));
   }
}