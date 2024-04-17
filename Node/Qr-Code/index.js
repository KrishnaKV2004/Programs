import fs from "fs";
import qr from "qrcode";
import inquirer from "inquirer";

inquirer

.prompt
([
    {
        "message" : "Your Name ? --> ",
        "name" : "userName"
    },
    {
        "message" : "Your Email ? -->  ",
        "name" : "userEmail"
    },
    {
        "message" : "Your Password ? --> ",
        "name" : "userPassword"
    },
    {
        "message" : "URL To Convert -->",
        "name" : "URL"
    }
])

.then
((answers) =>
{
    const url = answers.URL;

    qr.toFileStream(fs.createWriteStream("QR-Image.png"), url)

    const jsonString = JSON.stringify(answers, null, 4);

    fs.writeFile("Info.json", jsonString, (err) =>
    {
        if (err)
        {
            console.log("Something Went Wrong !");
        }
        else
        {
            console.log("File Saved Successfully !");
        }
    })
})

.catch
((error) =>
{
    console.log("OOPS ! Something Went Wrong");
    console.log(error);
})