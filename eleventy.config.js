const syntaxHighlight = require("@11ty/eleventy-plugin-syntaxhighlight");

module.exports = async function (eleventyConfig) {
    const { IdAttributePlugin } = await import("@11ty/eleventy");

    // Adds matching `id` attributes to the Markdown headings so the sidebar
    // table of contents can link to them.
    eleventyConfig.addPlugin(IdAttributePlugin);

    // Adds Prism token classes to fenced code blocks at build time. The colors
    // are defined in style.css, so no client-side JavaScript is required.
    eleventyConfig.addPlugin(syntaxHighlight);

    eleventyConfig.addPassthroughCopy("style.css");

    return {
        dir: {
            input: "src",
            includes: "_includes",
            output: "_site",
        },
    };
};
