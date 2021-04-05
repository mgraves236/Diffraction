% file1 = load('wave.bin')
file2 = load('wave2.bin')

hold on
% plot(file1(:,1), file1(:,2)/2, '--', 'Color', [133,105,199]/256, 'Linewidth', 2, 'HandleVisibility','on');
hold on 
plot(file2(:,1), file2(:,2), '-', 'Color', [133,105,199]/256, 'Linewidth', 2, 'HandleVisibility','on');
title('\lambda = 50')
grid on
axis tight
set(gca,'xticklabel',[])