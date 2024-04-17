import express from "express";
import morgan from "morgan";

const app = express();
const port = 3000;

//  Custom Middleware -->

function logger(req, res, next)
{
    console.log("Request Method --> ", req.method);
    console.log("Request URL --> ", req.url);
    next();
}

app.use(morgan("combined"));

//  Custom Middleware Call -->

app.use(logger);

//  Server Handlers -->

app.get("/", (req, res) =>{
    res.send("Hello");
});

app.listen(port, () =>
{
    console.log(`Server Running On Port ${port}`);
});