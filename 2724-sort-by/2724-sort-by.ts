function sortBy(arr: any[], fn: (item: any) => number): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
}
