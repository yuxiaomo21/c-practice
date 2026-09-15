# C Practice

C / C++ 学习练习仓库。

## 开发环境

| 项目 | 版本 |
|---|---|
| IDE | Visual Studio Community 2026 |
| 编译器 | MSVC 14.51 (`_MSC_VER` = 1951) |
| 平台工具集 | `v145` |
| C++ 标准 | C++20 |

## 项目列表

| 项目 | 说明 |
|---|---|
| `practice1` | 第一个练习项目 |

## 如何构建

**方式一：Visual Studio**

用 VS 打开 `practice1.slnx`，按 `F5` 运行 / `Ctrl+F5` 运行（不调试）。

**方式二：命令行**

```powershell
MSBuild.exe practice1.slnx /p:Configuration=Release /p:Platform=x64
```

产物位置：`x64\Release\practice1.exe`

## 目录说明

```
practice1/
├── practice1.cpp            # 源代码
├── practice1.slnx           # 解决方案文件（VS 2026 新格式）
├── practice1.vcxproj        # 项目文件
├── practice1.vcxproj.filters# VS 里的文件分组
└── .gitignore               # 忽略构建产物
```

> `x64/`、`.vs/` 是构建产物和 IDE 缓存，已被 `.gitignore` 排除，**不会**上传到 GitHub。

## 学习记录

| 日期 | 内容 |
|---|---|
| 2026 | 环境搭建完成，开始学习 C 语言 |
