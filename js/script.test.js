const { determineGameResult } = require("./script");

describe("game result", () => {
    test("r vs. r -> 0", () => {
        expect(determineGameResult("r", "r")).toBe(0);
    });

    test("r vs. p -> -1", () => {
        expect(determineGameResult("r", "p")).toBe(-1);
    });

    test("r vs. s -> 1", () => {
        expect(determineGameResult("r", "s")).toBe(1);
    });

    test("p vs. r -> 1", () => {
        expect(determineGameResult("p", "r")).toBe(1);
    });

    test("p vs. p -> 0", () => {
        expect(determineGameResult("p", "p")).toBe(0);
    });

    test("p vs. s -> -1", () => {
        expect(determineGameResult("p", "s")).toBe(-1);
    });

    test("s vs. r -> -1", () => {
        expect(determineGameResult("s", "r")).toBe(-1);
    });

    test("s vs. p -> 1", () => {
        expect(determineGameResult("s", "p")).toBe(1);
    });

    test("s vs. s -> 0", () => {
        expect(determineGameResult("s", "s")).toBe(0);
    });

    test("r vs. r !-> -1", () => {
        expect(determineGameResult("r", "r")).not.toBe(-1)
    })

    test("r vs. r !-> 1", () => {
        expect(determineGameResult("r", "r")).not.toBe(1)
    })
});
