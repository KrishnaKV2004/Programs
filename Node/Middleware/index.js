import express from "express";
import bodyParser from "body-parser";

import { dirname } from "path";
import { fileURLToPath } from "url";

const port = 3000;
const app = express();
const __dirname = dirname(fileURLToPath(import.meta.url));

app.use(bodyParser.urlencoded(
    {
        extended : true
    }
));

app.get("/", (req, res) =>
{
    res.sendFile(__dirname + "/public/index.html");
});

app.post("/submit", (req, res) =>
{
    console.log(req.body);
});

app.listen(port, () =>
{
    console.log(`Server Running On Port ${port}`);
});