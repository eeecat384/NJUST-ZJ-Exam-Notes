# 创建与启用仓库

这份指南适用于首次创建空仓库。你需要 GitHub 账号；推荐安装 Git 后从本地一次性上传完整文件，以保留 `.github` 等以点开头的目录。

## 1. 检查文件

解压完整压缩包，进入 `NJUST-ZJ-Exam-Notes` 文件夹。该文件夹的直接子项应包含 `README.md`、`CONTRIBUTING.md`、`courses`、`docs` 和 `.github`，而不是再套一层同名文件夹。Windows 文件资源管理器可开启“查看 → 显示 → 隐藏的项目”检查 `.github`。

示例课程目前没有真实资料。你可以保留它作为填写样例；删除时同步删除 `courses/README.md` 中的示例行。

发布前确认：项目介绍符合你的意图；你接受当前逐份标注权限的政策；在 GitHub 个人主页提供一个可用的私密联系渠道。无需把私人手机号或学号写进仓库。

## 2. 在 GitHub 创建空仓库

1. 登录 GitHub，点击右上角 `+` → `New repository`。
2. Owner 选择自己的账号；Repository name 填 `NJUST-ZJ-Exam-Notes`。
3. Description 可填：`南京理工大学紫金学院课程资料共享：笔记、复习提纲、练习解析与学习经验。`
4. 若准备公开分享，选择 Public；如果希望先自己检查，可先建 Private，检查完成后再调整可见性。
5. 不勾选自动创建 README，不添加 .gitignore 或 License：这些内容已在本地准备好，本套文件采用逐份授权政策。
6. 点击 `Create repository`，复制仓库的 HTTPS 地址。

## 3. 用 PowerShell 上传

先确保已安装 Git。打开解压后的 `NJUST-ZJ-Exam-Notes` 文件夹，在地址栏输入 `powershell` 并回车。逐行执行：

```powershell
git --version
git init
git branch -M main
git status
```

首次使用 Git 时，为当前仓库设置提交署名：

```powershell
git config user.name "你的公开昵称"
git config user.email "你的 GitHub 提交邮箱"
```

邮箱会进入提交记录。想隐藏个人邮箱时，从 GitHub Settings → Emails 复制自己账号的 noreply 地址，不要凭空填写别人的邮箱。

确认待提交文件后执行：

```powershell
git add .
git diff --cached --stat
git commit -m "docs: 初始化课程资料共享仓库"
git remote add origin https://github.com/YOUR-USERNAME/NJUST-ZJ-Exam-Notes.git
git push -u origin main
```

将 `YOUR-USERNAME` 替换为你的 GitHub 用户名；如果仓库属于组织，使用组织名。按 Git 提示完成浏览器登录；不要把账号密码或令牌写入文件、远程地址或聊天。以上命令只用于新建的本地仓库；如果提示 origin 已存在，先用 `git remote -v` 核对，不要盲目覆盖。

如果 push 提示远程已有提交，先停止并检查是否在创建仓库时生成了 README 等文件；不要强制推送。最容易理解的做法是将远程仓库克隆到新的文件夹，再复制本套文件进去、核对并提交。

## 4. 检查 GitHub 展示

1. 刷新仓库首页，确认 README 正常显示，课程索引、投稿指南与规则链接可打开。
2. 在 Issues 中点击 New issue，确认出现“资料投稿”“资料纠错”“资料需求”“权益与隐私反馈”四项。
3. 模板通常需位于默认分支才会生效。检查 Settings → Branches 或仓库默认分支设置，确保默认分支是 main。
4. 验证 PR 模板：创建一个测试分支，对 README 作一次无害修改，提交并发起 PR；确认正文自动出现检查清单。关闭该测试 PR 并删除测试分支即可，无需合并。
5. 不要使用真实敏感文件测试模板，也不需要提交一份真实试卷来验证流程。

## 5. 配置维护入口

- 在仓库 About 中填写简介，可添加 `njust-zj`、`course-notes`、`study-materials` 等主题。
- 在 Issues → Labels 创建 `submission`、`correction`、`request`、`rights`、`needs-info`、`approved`。模板未硬编码标签，因此未创建标签时也能使用。
- 在 Settings → Collaborators / Manage access 邀请共同维护者，只授予工作所需权限。
- 在 Settings → General 的合并设置中可开启 Squash merging。
- 在 Settings → Rules → Rulesets 或 Branches 的保护规则中，为 main 要求通过 PR 合并；有其他维护者时设置至少一次批准。只有自己维护时，先避免配置成必须获得无法提供的他人批准。具体可用项取决于账号方案和仓库可见性。
- 当前没有自动化检查工作流，不要设置尚不存在的必需状态检查。

## 6. 收录第一门真实课程

1. 按 `docs/DIRECTORY_SPEC.md` 创建课程目录并复制示例 README。
2. 添加一份有权公开的原创笔记，补齐作者昵称、学年、文件用途、来源和权限。
3. 将课程加入 `courses/README.md` 索引。
4. 新建投稿分支并发起 PR，按 `docs/REVIEW_POLICY.md` 留下检查记录。
5. 审核通过后合并，检查索引和下载是否正常，再邀请同学投稿。

## 7. 持续维护

定期查看纠错和权益反馈；变更课程文件时同步说明和索引。不要把 PR 合并视为正确性认证。发现隐私泄露时及时控制影响；删除当前文件不能自动删除历史或他人副本。

## GitHub 官方说明

- [创建仓库](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-new-repository)
- [将本地代码添加到 GitHub](https://docs.github.com/en/migrations/importing-source-code/using-the-command-line-to-import-source-code/adding-locally-hosted-code-to-github)
- [配置 Issue 模板](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository)
- [配置 PR 模板](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/creating-a-pull-request-template-for-your-repository)
- [受保护分支说明](https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches)
