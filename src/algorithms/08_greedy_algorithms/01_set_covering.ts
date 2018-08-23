let statesNeeded: Set = new Set(['mt', 'wa', 'or', 'id', 'nv', 'ut', 'ca', 'az']);

const stations: {
  kone: Set
  ktwo: Set
  kthree: Set
  kfour: Set
  kfive: Set
}  = {};

stations.kone = new Set(['id', 'nv', 'ut']);
stations.ktwo = new Set(['wa', 'id', 'mt']);
stations.kthree = new Set(['or', 'nv', 'ca']);
stations.kfour = new Set(['nv', 'ut']);
stations.kfive = new Set(['ca', 'az']);

const finalStations: Set = new Set();

while (statesNeeded.size) {
  let bestStation = null;
  let statesCovered = new Set();
  Object.keys(stations).forEach((station) => {
    const states = stations[station];
    const covered = new Set([...statesNeeded].filter(x => states.has(x)));
    if (covered.size > statesCovered.size) {
      bestStation = station;
      statesCovered = covered;
    }
  });
  statesNeeded = new Set([...statesNeeded].filter(x => !statesCovered.has(x)));
  finalStations.add(bestStation);
}

console.log(finalStations); // Set { 'kone', 'ktwo', 'kthree', 'kfive' }
