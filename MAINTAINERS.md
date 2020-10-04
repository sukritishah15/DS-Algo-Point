# Instructions for Maintainers

## Rules for assignment of Issues
1. Whoever creates the issue, gets the first priority while being assigned the issue, no matter at what position their comment lies. (Simple reasoning - They created the issue, because they wanted to claim it. They have put in the effort and should not suffer because someone else was faster than them, in asking for the issue.)
2. After that, whoever comments first, gets assigned.
3. If somebody(say person A) asks for the issue in multiple languages(say N languages) - 
- Check all the comments received so far, if no one has asked for the issue in the languages person A has asked for, assign person A in all the languages. (Preferble - Do not assign issue in more than 4 languages i.e. discard (N-4) languages and mention this in a comment. However, you can always, go by your gut.)
- If someone else(say person B) has asked for the issue in any of the N languages, then assign person B that language and remaining (N-1) languages to person A.
4. There is no hard and fast rule. Always, use your discretion. 
5. But the above rules are recommended, because - 
- An issue can at max. be assigned to 10 people at any point of time (Limit set by GitHub). So, if an issue has parts just like CPU Scheduling Issue, it would be difficult to restrict people to 1 language per issue.
- Assigning more than 4 languages per issue is discouraged because people are active while asking for the issue, but often do not make a PR for it timely. So, in such a case, the issue is left open for long, unnecesarily. Just a check. Despite, this, people do not make PR's on time.
- Add Hacktoberfest label. Add difficulty label. Add all 10 language labels.

## How to assign an issue.
1. People ask for issues in the comments. So, add a comment mention their username and the language(s) they are assigned the issue in. You can do that in a single comment if you are assigning multiple users at the same time, instead of adding 1 new comment per assignment (Preferable/Recommended).
2. Edit the Isssue Description and write double hashtag (use hashtag symbol) followed by space followed by "Assignees". And then you can add their usernames and the language(s) they are assigned.
3. Under assignees, select their username(Just click on it).
4. Remove the language labels for which assignments have been done.

## How to review a PR
1. Check that they have mentioned the Issue no. their PR fixes. This is important because - 
- If they mention issue no., we will get a reference to their PR in the Issue. This will help us close the issue later, as we will know if we have received code for that issue already or not.
- We will also ensure that only those who were assigned have created a PR for this issue.
2. Every PR should have 2 files if the PR solves the issue in 1 programming language only. The first file is the README.md file present in the programming language folder corresponding to which code is being submitten. Second file will be the code file. Always, check that files are added to the correct folder.
3. Check if they have provided Sample I/O, Time and Space Complexity in the code file or not. It is recommended that they provide it at the bottom of the file in a single multiline comment. However, sometimes contributors divide the comments and provide it at the top or somewhere in the middle. This is acceptable as long as they are using multiline comments. Because, single line comments make the code difficult to read (NOT RECOMMENDED).
4. Try to squash and merge. Though, simply merging works.
5. If there are Merge Conflicts, resolve if you can. Else, tag me. I'll resolve them.

### Check if I've added your name as a maintainer to the main README.md file correctly or not.

### Thank you for coming forward to help with this project.

