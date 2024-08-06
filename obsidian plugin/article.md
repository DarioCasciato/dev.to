**Leaving the Comfort Zone Behind: The Journey to Developing a Plugin for Obsidian.md**

In my daily work use of [Obsidian.md](https://obsidian.md/), something started to stress me out more and more: the way folders behaved when navigating through the vault. If you know Obsidian, you know how valuable it is to keep a clean and organized workspace, especially with a large number of files. But, there was a small feature that was noticeably not there – folders didn’t automatically collapse their subfolders when the parent folder was collapsed. This lack of automatic folder management led to a cluttered and overwhelming sidebar, and it was something I couldn't ignore.

### The "Wouldn't It Be Great If..." Moment

One day, after manually collapsing what felt like the number 1'547 nested folder, I had the classic developer thought: *Wouldn’t it be great if Obsidian had a feature that automatically collapsed all child folders when the parent folder is collapsed?* The idea was simple but practical, and I could see how it would improve the workflow for many users (like myself).

But, there was no existing feature or plugin that addressed this. That’s when the seed of developing a plugin started to take root in my mind.

### The Nervousness of Starting Something New

I was both excited and nervous about diving into the development of a plugin. I had developed software before, but creating a plugin that would integrate smoothly with Obsidian felt different. The main challenge was being sure that when a parent folder is collapsed, all its child folders would collapse too without having any other efforts to do so manually.

There was an underlying anxiety: *I have never used the Obsidian API*. The idea seemed simple, but the implementation was a different story. I was worried about the potential roadblocks and the the fear of not knowing enough to make it work.

### Getting My Hands Dirty: Developing the Plugin

Despite the nerves, I decided to take the plunge. I started by familiarizing myself with Obsidian’s plugin API and thinking about the rough processes that would be needed to have the desired functionality. The goal was clear, but the implementation needed to be just right.

After some trial and error – a version with a refresh command that was removed - and more than a few moments of head-scratching – I finally got the core functionality working. The plugin I developed, which I named "Auto Folder Collapse," made sure that whenever a parent folder was collapsed, all its child folders would also collapse. It was a small tweak, but it had a veeery noticeable impact on the overall usability of Obsidian.

(GIF)

### The Pull Request: A New Kind of Anxiety

With the plugin (finally) functioning as intended, the next step was to share it with the world. This meant forking the official [obsidian-release](https://github.com/obsidianmd/obsidian-releases) repo, adding my plugin, and creating a pull request to have it included in the official community plugins list.
(a more detailed description on how to publish a plugin: [Obsidian: Submit your plugin](https://docs.obsidian.md/Plugins/Releasing/Submit+your+plugin))

This was more challenging than i thought, since this was the first time for me to contribute to a open-source project. The process of creating a pull request was straightforward, but I couldn’t help but worry about the potential feedback. *Would the maintainers find the plugin useful?* *What if they pointed out flaws I hadn’t noticed?* and *What if it doesn’t even fit the demands of Obsidian?*

I submitted the pull request and then came the waiting game.

### The Sweet Moment of Approval

Aftfer some description-fixing (and "Refresh-Command" removal), to my relief and excitement, the plugin was approved and merged into the official community plugins list. Seeing "Auto Folder Collapse" listed among other plugins in the community felt incredibly rewarding. It was a validation of the work I had put in and the idea that started as a small frustration.

### Conclusion: Reflecting on the Experience

Developing and releasing "Auto Folder Collapse" was a learning experience in many ways. It wasn’t just about coding; it was about stepping out of my comfort zone, contributing to a community, and seeing an idea come to life in a way that could help others. The feeling of providing something that the world needs/wants is surely one of the best. After 6 days since the release, the plugin has been downloaded 132 times, which is a number I never expected to reach in this time.

Link to the Repository: [Auto Folder Collapse](https://github.com/DarioCasciato/obsidian-auto-folder-collapse)

For anyone out there with a similar idea/itch – whether it’s a small feature you wish existed or a bug that needs fixing – I encourage you to take that leap. The journey might be a bit nerve-wracking, but the outcome can be incredibly rewarding. Plus, you never know how many people might benefit from that small idea you had. **Always remember that your comfort zone is a nice place, but nothing ever grows there.**

Thanks for reading! If you have any thoughts or questions, feel free to leave a comment. Happy coding!