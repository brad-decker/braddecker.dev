import { useRef, useState, useEffect } from 'react';

const titles = ['software architect', 'software engineer', 'UI engineer', 'technical leader', 'mentor'];

export function useTitleLoop(loopStarted: boolean, delay: number = 500): string {
  const titleIncrement = useRef(0);
  const [title, setTitle] = useState(titles[titleIncrement.current]);
  useEffect(() => {
    let intervalId: NodeJS.Timeout | null = null;
    if (loopStarted) {
      setTimeout(() => {
        intervalId = setInterval(() => {
          if (titleIncrement.current < titles.length - 1) {
            titleIncrement.current++;
          } else {
            titleIncrement.current = 0;
          }
          setTitle(titles[titleIncrement.current]);
        }, 1000);
      }, delay);
    }
    return () => {
      if (intervalId) {
        clearInterval(intervalId);
      }
    };
  }, [loopStarted]);
  return title;
}
