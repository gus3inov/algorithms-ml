export const greet2 = (name: string): void => console.log(`how are you ${name} ?`);

export const bye = (): void => console.log('ok bye');

export const greet = (name: string): void => {
    console.log(`hello ${name} !`);
    greet2(name);
    console.log('getting ready to say bye...');
    bye();
};

export const main = () => greet<string>('adit');
