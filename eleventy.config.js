module.exports = async function (eleventyConfig) {
    const { IdAttributePlugin } = await import("@11ty/eleventy");

    // Adds matching `id` attributes to the Markdown headings so the sidebar
    // table of contents can link to them.
    eleventyConfig.addPlugin(IdAttributePlugin);

    eleventyConfig.addPassthroughCopy("style.css");
    eleventyConfig.addPassthroughCopy("images");

    return {
        dir: {
            input: "src",
            includes: "_includes",
            output: "_site",
        },
    };
};
