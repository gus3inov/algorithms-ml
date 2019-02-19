const personIsSeller = (name: string): boolean => name[name.length - 1] === 'm';
const graph: any = {};

graph.you = ['alice', 'bob', 'claire'];
graph.bob = ['anuj', 'peggy'];
graph.alice = ['peggy'];
graph.claire = ['thom', 'jonny'];
graph.anuj = [];
graph.peggy = [];
graph.thom = [];
graph.jonny = [];

const search = (name: string): boolean => {
  let searchQueue: string[] = [];
  searchQueue = searchQueue.concat(graph[name]);

  const searched = [];
  while(searchQueue.length) {
    const person: string = searchQueue.shift();

    if (searched.indexOf(person == -1)) {
      if (personIsSeller(person)) {
        console.log(`${person} is a mongo seller !`);
        return true;
      }

      searchQueue = searchQueue.concat(graph[person]);
      searched.push(person);
    }
  }

  return false;
};

search('you');
