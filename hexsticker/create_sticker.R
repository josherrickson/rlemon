library(ggplot2)
library(hexsticker)
library(ggnetwork)
library(sna)

set.seed(36)
n <- network(rgraph(12, tprob = 0.1), directed = TRUE)

n %v% "family" <- c(rep("a", 5), "b", rep("a", 6))

gn <- ggnetwork(n)
(g <- ggplot(gn, aes(x = x, y = y, xend = xend, yend = yend)) +
  geom_edges() +
  geom_nodes(aes(shape = family), cex = 2.9, stroke = .7) +
  theme(axis.title.x=element_blank(),
        axis.text.x=element_blank(),
        axis.ticks.x=element_blank(),
        axis.title.y=element_blank(),
        axis.text.y=element_blank(),
        axis.ticks.y=element_blank(),
        legend.position = "none",
        panel.border = element_blank(),
        panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(),
        panel.background = element_rect(fill = "transparent", color = NA),
        plot.background = element_rect(fill = "transparent", color = NA)) +
 scale_shape_manual(values=c(16, 1)))

sysfonts::font_add("AppleGothic", "/System/Library/Fonts/Supplemental/AppleGothic.ttf")

sticker(g, package = "rlem  n", filename = "rlemon.png",
        s_width = 2, s_height = 2, s_y = .9, s_x = .7,
        p_x = 1.38, p_y = .57, p_size = 17, p_color = "black", p_family="AppleGothic",
        h_color = "#FAD934", h_fill = "#ffe175")

## Afterwards, do the following edits in editor:
## 1) remove extraneous edges/nodes outside of Hex
## 2) Trim slightly extruding line into "o"
