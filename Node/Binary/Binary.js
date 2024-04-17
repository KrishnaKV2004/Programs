import readline from "readline"

const rl = readline.createInterface
({
    input: process.stdin,
    output: process.stdout
})

function stringToBinary(inputString)
{
    return inputString.split('').map(char =>
    {
        const binary = char.charCodeAt(0).toString(2)
        return '0'.repeat(8 - binary.length) + binary
    }).join(' ')
}

function binaryToString(binaryString)
{
    return binaryString.split(' ').map(binary =>
    {
        return String.fromCharCode(parseInt(binary, 2))
    }).join('')
}

function main()
{
    console.clear()

    rl.question('Choose An Option -->\n\n[B] Convert String To Binary\n[S] Convert Binary To String\n[E] Exit\n\nChoose Operation [B/S/E] --> ', (choice) =>
    {
        if (choice === 'B' || choice === 'b')
        {
            rl.question('\nEnter A String --> ', (inputString) =>
            {
                const binary = stringToBinary(inputString)
                console.log(`Binary: ${binary}`)
                askToContinue()
            })
        }
        else if (choice === 'S' || choice === 's')
        {
            rl.question('\nEnter Binary (Space-Separated) --> ', (binaryString) =>
            {
                const string = binaryToString(binaryString)
                console.log(`String: ${string}`)
                askToContinue()
            })
        }
        else if (choice === 'E' || choice === 'e')
        {
            rl.close()
        }
        else
        {
            console.log('Invalid Choice !')
            askToContinue()
        }
    })
}

function askToContinue()
{
    rl.question('\nDo You Want To Continue ? [Y/N] --> ', (answer) =>
    {
        if (answer.toUpperCase() === 'Y')
        {
            main()
        } 
        else if (answer.toUpperCase() === 'N')
        {
            rl.close()
        }
        else
        {
            console.log('Invalid Choice !')
            askToContinue()
        }
    })
}

main()