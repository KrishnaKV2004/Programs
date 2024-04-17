import express from "express"

const app = express()
const port = 3000

app.get("/", (req, res) =>
{
    res.send("<h1>Sending Request !</h1>")
})

app.get("/contact", (req, res) =>
{
    res.send("<h1>Contact --> 9997688555</h1>")
})

app.get("/about", (req, res) =>
{
    res.send("<h1>Krishna Verma</h1>")
})

app.post("/register", (req, res) =>
{
    res.sendStatus(201);
})

app.put("/user/krishna", (req, res) =>
{
    res.sendStatus(200);
})

app.patch("/user/krishna", (req, res) =>
{
    res.sendStatus(200);
})

app.delete("/user/krishna", (req, res) =>
{
    res.sendStatus(200);
})

app.listen(port, () =>
{
    console.log(`Server Running On Port ${port}`)
})